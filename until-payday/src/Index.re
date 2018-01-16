let payDayDateKey = "PAYDAY_DATE";

let home =
  switch (Js.Dict.get(Node.Process.process##env, "HOME")) {
  | Some(path) => path
  | None => ""
  };

let configPath = {j|$home/.paydayrc|j};

let isPayDayDate = (keyValue: KeyValueFile.keyvalue) =>
  keyValue.key == payDayDateKey;

let today = Js.Date.make();

let currentYear = Js.Date.getUTCFullYear(today);

let daysUntilPayday =
    (today: Js.Date.t, {value: payday}: KeyValueFile.keyvalue) => {
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
  int_of_float(days);
};

let makeOutputString = (days: int) => {j|There are $days days until payday|j};

let outputString =
  try (
    KeyValueFile.paydayFile(configPath)
    |> List.find(isPayDayDate)
    |> daysUntilPayday(today)
    |> makeOutputString
  ) {
  | Js.Exn.Error(e) =>
    switch (Js.Exn.message(e)) {
    | Some(message) => Error.checkErrorMessage(message).message
    | None => Error.genericError.message
    }
  };

Js.log(outputString);