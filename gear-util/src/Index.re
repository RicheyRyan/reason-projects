let cadence = 90.0;

let development = 6.2;

Js.log("Hello, welcome to GearUtil!");

Js.log(
  "Cadence: "
  ++ (cadence |> string_of_float)
  ++ ", Development: "
  ++ (development |> string_of_float)
);

Js.log(
  "Cadence and metres of development to km/hr: "
  ++ (GearUtil.cadenceToSpeedKm(cadence, development) |> string_of_float)
);

Js.log(
  "Cadence and metres of development to mi/hr: "
  ++ (GearUtil.cadenceToSpeedMiles(cadence, development) |> string_of_float)
);
