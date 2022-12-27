# 3: Jenkins

[Jenkins Docker Server](https://github.com/jenkinsci/docker/blob/master/README.md)

```bash
docker run -d \
    --name jenkins-server \
    -p 8080:8080 \
    -p 50000:50000 \
    -v jenkins_home:/var/jenkins_home \
    -v /var/run/docker.sock:/var/run/docker.sock \
    rogueraptor7/jenkins-docker
```

Pipeline build command:

```bash
#!/bin/bash

cd 1-volumes-guis/edge_detect
pytest

if [[ $? -eq 0 ]]
then
  curl -H "Title: Edge detect test successful" -d "Edge detect test has successfully finished" https://ntfy.sh/3081w_jenkins
  exit 0
else
  curl -H "Title: Edge detect test failed" -d "Edge detect test has failed" https://ntfy.sh/3081w_jenkins
  exit 1
fi
```