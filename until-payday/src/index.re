let today = Js.Date.make();

let currentYear = Js.Date.getUTCFullYear(today);

let daysUntilPayday =
    ({value: payday}: KeyValueFile.keyvalue, today: Js.Date.t) => {
  let numToday = DateUtil.numDayOfDate(today);
  let numDays = payday -. numToday;
  let days =
    if (numDays > 0.0) {
      numDays;
    } else {
      DateUtil.monthOfDate(today)
      |> DateUtil.daysInMonth(currentYear)
      |> DateUtil.daysLeftInMonth(numToday)
      |> (+.)(payday);
    };
  let outputDays = int_of_float(days);
  {j|There are $outputDays days until payday|j};
};

let outputString = daysUntilPayday(KeyValueFile.paydayValue(), today);

Js.log(outputString);