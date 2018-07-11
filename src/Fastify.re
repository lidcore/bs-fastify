type t;

[@bs.deriving abstract]
type serverOptions = {
  bodyLength: int,
  caseSensitive: bool,
  http2: bool,
  ignoreTrailingSlash: bool,
  maxParamLength: int,
};

type response;

[@bs.deriving abstract]
type request = {params: Js.Dict.t(string)};

type handler = (. request, response) => unit;

type middleware;

module Router = {
  [@bs.send] external delete : (t, string, handler) => unit = "";
  [@bs.send] external get : (t, string, handler) => unit = "";
  [@bs.send] external head : (t, string, handler) => unit = "";
  [@bs.send] external options : (t, string, handler) => unit = "";
  [@bs.send] external patch : (t, string, handler) => unit = "";
  [@bs.send] external post : (t, string, handler) => unit = "";
  [@bs.send] external put : (t, string, handler) => unit = "";
  [@bs.send] external use : (t, middleware) => unit = "";
};

[@bs.send] external sendJson : (response, Js.t('a)) => unit = "send";
[@bs.send] external sendText : (response, string) => unit = "send";

[@bs.send]
external listen : (t, int, string, (string, string) => unit) => unit = "";

[@bs.module] [@bs.new] external init : serverOptions => t = "fastify";

let init =
    (
      ~bodyLength=1048576,
      ~caseSensitive=true,
      ~http2=false,
      ~ignoreTrailingSlash=false,
      ~maxParamLength=100,
      (),
    ) => {
  let options =
    serverOptions(
      ~bodyLength,
      ~caseSensitive,
      ~http2,
      ~ignoreTrailingSlash,
      ~maxParamLength,
    );
  init(options);
};
