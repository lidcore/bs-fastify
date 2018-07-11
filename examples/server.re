open Fastify.Router;

let server = Fastify.init();

get(server, "/ping", (. _, resp) =>
  Fastify.sendJson(resp, {"reply": "pong"})
);

head(server, "/ping", (. _, resp) => Fastify.sendText(resp, ""));

Fastify.listen(server, 3000, "0.0.0.0", (_, _) => ());
