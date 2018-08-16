type error = {message: string};

let genericError = {message: "Error: An issue occured"};

let notFoundError = {message: "We could not find your .paydayrc file!"};

let isError = (str: Js.String.t) => Js.String.indexOf("Error:", str) > (-1);

let fileNotFound = (message: Js.String.t) =>
  Js.String.indexOf("no such file or directory", message) > (-1);

let checkErrorMessage = (message: Js.String.t) =>
  fileNotFound(message) ? notFoundError : genericError;
