let metreToKm = Unit.Distance.convert(Unit.Distance.Metre, Unit.Distance.Km);

let metreToMile =
  Unit.Distance.convert(Unit.Distance.Metre, Unit.Distance.Mile);

let minuteToHour = Unit.Time.convert(Unit.Time.Minute, Unit.Time.Hour);

let distancePerMinute = (cadence: float, development: float) =>
  cadence *. development;

let distancePerHour = (cadence: float, development: float) =>
  distancePerMinute(cadence: float, development: float) |> minuteToHour;

let cadenceToSpeedKm = (cadence: float, metresOfDevelopment: float) =>
  metreToKm(metresOfDevelopment) |> distancePerHour(cadence);

let cadenceToSpeedMiles = (cadence: float, metresOfDevelopment: float) =>
  metreToMile(metresOfDevelopment) |> distancePerHour(cadence);