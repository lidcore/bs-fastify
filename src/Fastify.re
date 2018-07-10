type t;

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  http2: bool,
  [@bs.optional]
  ignoreTrailingSlash: bool,
};

type response;

[@bs.deriving abstract]
type request = {params: Js.Dict.t(string)};

type handler = (. request, response) => unit;

[@bs.module] [@bs.new] external init : options => t = "fastify";

[@bs.send] external get : (t, string, handler) => unit = "";

[@bs.send] external send : (response, Js.t('a)) => unit = "";

[@bs.send]
external listen : (t, int, string, (string, string) => unit) => unit = "";

let init = (~http2=false, ~ignoreTrailingSlash=false, ()) => {
  let options = options(~http2, ~ignoreTrailingSlash, ());
  init(options);
};
