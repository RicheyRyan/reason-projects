let numDayOfDate = date => Js.Date.getUTCDate(date);

let monthOfDate = d => Js.Date.getUTCMonth(d) +. 1.0;

let daysInMonth = (year, month) =>
  Js.Date.getDate(Js.Date.makeWithYMD(~year, ~month, ~date=0.0, ()));

let daysLeftInMonth = (daysSoFar, monthDays) => monthDays -. daysSoFar;