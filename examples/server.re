let server = Fastify.init();

Fastify.get(server, "/ping", (. req, resp) =>
  Fastify.send(resp, {"reply": "pong"})
);

Fastify.listen(server, 3000, "0.0.0.0", (_, _) => ());
