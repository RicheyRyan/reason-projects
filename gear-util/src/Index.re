let cadence = 90.0;

let development = 6.2;

let wheelDiameter = 26.38;

let chainring = 46.;

let cog = 16.;

let crank = 165.;

let print = (~label, ~value) => Js.log({j|$label: $value|j});

Js.log("Hello, welcome to GearUtil!");

print(~label="Cadence", ~value=cadence |> string_of_float);

print(~label="Development", ~value=development |> string_of_float);

print(~label="Wheel Diameter", ~value=wheelDiameter |> string_of_float);

print(~label="Chainring", ~value=chainring |> string_of_float);

print(~label="Cog", ~value=cog |> string_of_float);

print(~label="Crank Length", ~value=crank |> string_of_float);

Js.log("===========================================");

print(
  ~label="Cadence and metres of development to km/hr",
  ~value=Util.cadenceToSpeedKm(cadence, development) |> string_of_float
);

print(
  ~label="Cadence and metres of development to mi/hr",
  ~value=Util.cadenceToSpeedMiles(cadence, development) |> string_of_float
);

print(
  ~label="Gear inches",
  ~value=Util.gearInches(wheelDiameter, chainring, cog) |> string_of_float
);

print(
  ~label="Greatest common divisor of 54 and 24",
  ~value=Util.greatestCommonDivisor(54., 24.) |> string_of_float
);

print(
  ~label="Lowest fraction of 64/22",
  ~value=Util.lowestFraction(64., 22.) |> (fraction => {j|$fraction|j})
);

print(
  ~label="Metres of development",
  ~value=
    Util.metresOfDevelopment(~wheelDiameter, ~chainring, ~cog)
    |> string_of_float
);

print(
  ~label="Skid patches",
  ~value=Util.skidPatches(chainring, cog) |> string_of_float
);

print(
  ~label="Ambidextrous skid patches",
  ~value=Util.skidPatches(chainring, 17.0) |> string_of_float
);

print(
  ~label="Gain ratio",
  ~value=
    Util.gainRatio(~wheelDiameter, ~crank, ~chainring, ~cog) |> string_of_float
);

print(
  ~label="Equivalent gears",
  ~value=
    Util.equivalentGear(chainring, cog, Belt.Array.range(1,100)) |> List.map(({numerator, denominator}:Util.fraction) => {j| $numerator/$denominator|j})
);
