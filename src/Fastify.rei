type t;

[@bs.deriving abstract]
type serverOptions = {
  bodyLength: int,
  caseSensitive: bool,
  http2: bool,
  ignoreTrailingSlash: bool,
  maxParamLength: int,
};

let init:
  (
    ~bodyLength: int=?,
    ~caseSensitive: bool=?,
    ~http2: bool=?,
    ~ignoreTrailingSlash: bool=?,
    ~maxParamLength: int=?,
    unit
  ) =>
  t;

type response;

[@bs.deriving abstract]
type request = {params: Js.Dict.t(string)};

type handler = (. request, response) => unit;

type middleware;

module Router: {
  let delete: (t, string, handler) => unit;
  let get: (t, string, handler) => unit;
  let head: (t, string, handler) => unit;
  let options: (t, string, handler) => unit;
  let patch: (t, string, handler) => unit;
  let post: (t, string, handler) => unit;
  let put: (t, string, handler) => unit;
  let use: (t, middleware) => unit;
};

let sendJson: (response, Js.t('a)) => unit;
let sendText: (response, string) => unit;
let listen: (t, int, string, (string, string) => unit) => unit;
