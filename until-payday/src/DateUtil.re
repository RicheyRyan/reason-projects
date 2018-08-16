let numDayOfDate = (date: Js.Date.t) => Js.Date.getUTCDate(date);

let monthOfDate = (date: Js.Date.t) => Js.Date.getUTCMonth(date) +. 1.0;

let daysInMonth = (year: float, month: float) =>
  Js.Date.getDate(Js.Date.makeWithYMD(~year, ~month, ~date=0.0, ()));

let daysLeftInMonth = (daysSoFar: float, monthDays: float) =>
  monthDays -. daysSoFar;
