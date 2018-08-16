type fraction = {
  numerator: float,
  denominator: float
};

let isEvenFloat = x => mod_float(x, 2.0) == 0.0;

let metreToKm = Unit.Distance.convert(Unit.Distance.Metre, Unit.Distance.Km);

let metreToMile =
  Unit.Distance.convert(Unit.Distance.Metre, Unit.Distance.Mile);

let inchToMetre =
  Unit.Distance.convert(Unit.Distance.Inch, Unit.Distance.Metre);

let mmToInch = Unit.Distance.convert(Unit.Distance.Mm, Unit.Distance.Inch);

let minuteToHour = Unit.Time.convert(Unit.Time.Minute, Unit.Time.Hour);

let distancePerMinute = (cadence: float, development: float) =>
  cadence *. development;

let distancePerHour = (cadence: float, development: float) =>
  distancePerMinute(cadence: float, development: float) |> minuteToHour;

let cadenceToSpeedKm = (cadence: float, metresOfDevelopment: float) =>
  metreToKm(metresOfDevelopment) |> distancePerHour(cadence);

let cadenceToSpeedMiles = (cadence: float, metresOfDevelopment: float) =>
  metreToMile(metresOfDevelopment) |> distancePerHour(cadence);

let equivalentGear = (chainring: float, cog: float, range: array(int)) =>
  chainring
  /. cog
  |> (ratio => {numerator: ratio, denominator: 1.0})
  |> (
    baseRatio =>
      Belt.Array.reduce(
        range,
        [],
        (gears, i) => {
          let newRatio = {
            numerator: baseRatio.numerator *. float_of_int(i),
            denominator: baseRatio.denominator *. float_of_int(i)
          };
          isEvenFloat(newRatio.numerator)
          && newRatio.numerator < 60.
          && newRatio.denominator > 10. ?
            List.concat([gears, [newRatio]]) : gears;
        }
      )
  );

let gearInches = (wheelDiameter: float, chainring: float, cog: float) =>
  wheelDiameter *. (chainring /. cog);

/* Euclidean algorithm */
let rec greatestCommonDivisor = (x: float, y: float) =>
  y > 0.0 ? greatestCommonDivisor(y, mod_float(x, y)) : x;

let lowestFraction = (numerator: float, denominator: float) =>
  greatestCommonDivisor(numerator, denominator)
  |> (gcd => {numerator: numerator /. gcd, denominator: denominator /. gcd});

let metresOfDevelopment =
    (~wheelDiameter: float, ~chainring: float, ~cog: float) =>
  gearInches(wheelDiameter, chainring, cog)
  |> inchToMetre
  |> (gearMetre => gearMetre *. Js.Math._PI);

let skidPatches = (chainring: float, cog: float) =>
  lowestFraction(chainring, cog) |> (gearRatio => gearRatio.denominator);

let ambidextrousSkidPatches = (chainring: float, cog: float) =>
  skidPatches(chainring, cog)
  |> (patches => isEvenFloat(patches) ? patches : patches *. 2.0);

let radiusRatio = (~wheelDiameter: float, ~crank: float) =>
  wheelDiameter /. 2.0 /. mmToInch(crank);

let gainRatio =
    (~wheelDiameter: float, ~crank: float, ~chainring: float, ~cog: float) =>
  radiusRatio(~wheelDiameter, ~crank) |> (ratio => ratio *. chainring /. cog);
