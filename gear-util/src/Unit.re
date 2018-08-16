module Distance = {
  type measure =
    | Mm
    | Cm
    | Inch
    | Metre
    | Km
    | Mile;
  type ratio = {
    mm: float,
    cm: float,
    inch: float,
    metre: float,
    km: float,
    mile: float
  };
  /* TODO: double check all these ratios */
  let mm = {
    mm: 1.,
    cm: 1000.,
    inch: 0.0393701,
    metre: 100.0,
    km: 100000.,
    mile: 160934.
  };
  let cm = {
    mm: 1000.,
    cm: 1.,
    inch: 0.393701,
    metre: 100.0,
    km: 100000.,
    mile: 160934.
  };
  let inch = {
    mm: 254.,
    cm: 2.54,
    inch: 1.,
    metre: 0.0254,
    km: 0.0000254,
    mile: 0.000015783
  };
  let metre = {
    mm: 1000.0,
    cm: 100.0,
    inch: 39.3701,
    metre: 1.0,
    km: 0.001,
    mile: 0.000621371
  };
  let km = {
    mm: 100000.0,
    cm: 100000.0,
    inch: 39370.1,
    metre: 0.0001,
    km: 1.0,
    mile: 0.62137
  };
  let mile = {
    mm: 1609040.,
    cm: 160904.0,
    inch: 63360.,
    metre: 1609.04,
    km: 1.60904,
    mile: 1.0
  };
  let convertTarget = (conversion: ratio, target: measure, unit: float) =>
    switch target {
    | Mm => unit *. conversion.mm
    | Cm => unit *. conversion.cm
    | Inch => unit *. conversion.inch
    | Metre => unit *. conversion.metre
    | Km => unit *. conversion.km
    | Mile => unit *. conversion.mile
    };
  let convert = (base: measure, target: measure, unit: float) =>
    (
      switch base {
      | Mm => mm
      | Cm => cm
      | Inch => inch
      | Metre => metre
      | Km => km
      | Mile => mile
      | Cm => cm
      | Inch => inch
      }
    )
    |> (ratio => convertTarget(ratio, target, unit));
};

module Time = {
  type measure =
    | Year
    | Day
    | Week
    | Hour
    | Minute
    | Second;
  type ratio = {
    second: float,
    minute: float,
    hour: float,
    day: float,
    week: float,
    year: float
  };
  let second = {
    second: 3600.0,
    minute: 60.,
    hour: 1.,
    day: 0.0416667,
    week: 0.00595238571429,
    year: 0.0001141553424658356045
  };
  let minute = {
    second: 3600.0,
    minute: 1.,
    hour: 60.,
    day: 0.0416667,
    week: 0.00595238571429,
    year: 0.0001141553424658356045
  };
  let hour = {
    second: 3600.0,
    minute: 60.,
    hour: 1.,
    day: 0.0416667,
    week: 0.00595238571429,
    year: 0.0001141553424658356045
  };
  let day = {
    second: 3600.0,
    minute: 60.,
    hour: 1.,
    day: 0.0416667,
    week: 0.00595238571429,
    year: 0.0001141553424658356045
  };
  let week = {
    second: 3600.0,
    minute: 60.,
    hour: 1.,
    day: 0.0416667,
    week: 0.00595238571429,
    year: 0.0001141553424658356045
  };
  let month = {
    second: 3600.0,
    minute: 60.,
    hour: 1.,
    day: 0.0416667,
    week: 0.00595238571429,
    year: 0.0001141553424658356045
  };
  let year = {
    second: 3600.0,
    minute: 60.,
    hour: 1.,
    day: 0.0416667,
    week: 0.00595238571429,
    year: 0.0001141553424658356045
  };
  let convertTarget = (conversion: ratio, target: measure, unit: float) =>
    switch target {
    | Second => unit *. conversion.second
    | Minute => unit *. conversion.minute
    | Hour => unit *. conversion.hour
    | Day => unit *. conversion.day
    | Week => unit *. conversion.week
    | Year => unit *. conversion.year
    };
  let convert = (base: measure, target: measure, unit: float) =>
    (
      switch base {
      | Second => second
      | Minute => minute
      | Hour => hour
      | Day => day
      | Week => week
      | Year => year
      }
    )
    |> (ratio => convertTarget(ratio, target, unit));
};
