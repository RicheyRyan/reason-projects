let today = Js.Date.make();

let currentYear = Js.Date.getUTCFullYear(today);

let numDayOfDate = date => Js.Date.getUTCDate(date);

let monthOfDate = d => Js.Date.getUTCMonth(d) +. 1.0;

let daysInMonth = (year, month) =>
  Js.Date.getDate(Js.Date.makeWithYMD(~year, ~month, ~date=0.0, ()));

let daysLeftInMonth = (daysSoFar, monthDays) => monthDays -. daysSoFar;

let home =
  switch (Js.Dict.get(Node.Process.process##env, "HOME")) {
  | Some(path) => path
  | None => ""
  };

let configPath = {j|$home/.paydayrc|j};

type error = {message: string};

let genericError = {message: "An issue occured"};

let notFoundError = {message: "We could not find your .paydayrc file!"};

let fileNotFound = message =>
  Js.String.indexOf("no such file or directory", message) > (-1);

let checkErrorMessage = message =>
  fileNotFound(message) ? notFoundError : genericError;

let desiredContent = message =>
  Js.String.indexOf("PAYDAY_DATE", message) > (-1);

let paydayValue = paydayFile =>
  float_of_string(Js.String.split("=", paydayFile)[1]);

let daysUntilPayday = (payday, today) => {
  let numToday = numDayOfDate(today);
  let numDays = payday -. numToday;
  let days =
    if (numDays > 0.0) {
      numDays;
    } else {
      daysLeftInMonth(numToday, daysInMonth(currentYear, monthOfDate(today)))
      +. payday;
    };
  let outputDays = int_of_float(days);
  {j|There are $outputDays days until payday|j};
};

let result =
  try (Node.Fs.readFileAsUtf8Sync(configPath)) {
  | Js.Exn.Error(e) =>
    switch (Js.Exn.message(e)) {
    | Some(message) => checkErrorMessage(message).message
    | None => genericError.message
    }
  };

let outputString =
  desiredContent(result) ?
    daysUntilPayday(paydayValue(result), today) : result;

Js.log(outputString);