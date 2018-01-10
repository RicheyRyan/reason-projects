open Error;

let home =
  switch (Js.Dict.get(Node.Process.process##env, "HOME")) {
  | Some(path) => path
  | None => ""
  };

let configPath = {j|$home/.paydayrc|j};

let desiredContent = message =>
  Js.String.indexOf("PAYDAY_DATE", message) > (-1);

let paydayValue = paydayFile =>
  float_of_string(Js.String.split("=", paydayFile)[1]);

let paydayFromFile = () =>
  try (Node.Fs.readFileAsUtf8Sync(configPath)) {
  | Js.Exn.Error(e) =>
    switch (Js.Exn.message(e)) {
    | Some(message) => checkErrorMessage(message).message
    | None => genericError.message
    }
  };