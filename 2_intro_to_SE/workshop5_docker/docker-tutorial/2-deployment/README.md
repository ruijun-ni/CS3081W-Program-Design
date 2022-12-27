# 2: Deploying Docker Images

1. [Factorio](https://github.com/factoriotools/factorio-docker)
```bash
docker run -d \
    -p 34197:34197/udp \
    -p 27015:27015/tcp \
    -v factorio:/factorio \
    --name factorio \
    factoriotools/factorio 
```

```bash 
docker logs -f factorio
```

2. [Valheim](https://hub.docker.com/r/lloesche/valheim-server)
```bash
docker run -d \
    --name valheim-server \
    --cap-add=sys_nice \
    --stop-timeout 120 \
    -p 2456-2457:2456-2457/udp \
    -v valheim_config:/config \
    -v valheim_data:/opt/valheim \
    -e SERVER_NAME="Corey's Server" \
    -e WORLD_NAME="Neotopia" \
    -e SERVER_PASS="secret" \
    lloesche/valheim-server
```

```bash 
docker logs -f valheim-server
```

3. Jenkins (see `../3-jenkins`)
