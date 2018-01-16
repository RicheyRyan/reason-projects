open Error;

type keyvalue = {
  key: string,
  value: float
};

let validContent = (line: Js.String.t) => Js.String.indexOf("=", line) > (-1);

let readFile = (path: string) =>
  try (Node.Fs.readFileAsUtf8Sync(path)) {
  | Js.Exn.Error(e) =>
    switch (Js.Exn.message(e)) {
    | Some(message) => checkErrorMessage(message).message
    | None => genericError.message
    }
  };

let parseLine = (acc: list(keyvalue), line: Js.String.t) => {
  let parsedLine = Js.String.split("=", line);
  if (Array.length(parsedLine) == 2) {
    List.concat([
      acc,
      [{key: parsedLine[0], value: parsedLine[1] |> float_of_string}]
    ]);
  } else {
    acc;
  };
};

let formatFileContent = (fileContent: Js.String.t) =>
  Js.String.split("\n", fileContent)
  |> Array.to_list
  |> List.fold_left(parseLine, []);

let paydayFile = (configPath: string) =>
  readFile(configPath) |> formatFileContent;