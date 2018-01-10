let today = Js.Date.make();

let currentYear = Js.Date.getUTCFullYear(today);

let daysUntilPayday = (payday, today) => {
  let numToday = DateUtil.numDayOfDate(today);
  let numDays = payday -. numToday;
  let days =
    if (numDays > 0.0) {
      numDays;
    } else {
      DateUtil.daysLeftInMonth(
        numToday,
        DateUtil.daysInMonth(currentYear, DateUtil.monthOfDate(today))
      )
      +. payday;
    };
  let outputDays = int_of_float(days);
  {j|There are $outputDays days until payday|j};
};

let result = KeyValueFile.paydayFromFile();

let outputString =
  KeyValueFile.desiredContent(result) ?
    daysUntilPayday(KeyValueFile.paydayValue(result), today) : result;

Js.log(outputString);