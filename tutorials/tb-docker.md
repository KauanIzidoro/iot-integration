## Setting Up ThingsBoard with Docker for IoT Projects

> Requirements: 
- `Docker Desktop`
- `Linux/WSL Terminal`


> Step 1. Create new project:

```bash
mkdir <project_name>
cd <project_name>
```

> Step 2. Create and copy a `docker-compose.yml` following the [documentation](https://thingsboard.io/docs/user-guide/install/docker-windows/):

```bash
touch docker-compose.yml
vim docker-compose.yml
```

> Step 3. Paste the following configuration into the `docker-compose.yml` file:
```yml
services:
  mytb:
    restart: always
    image: "thingsboard/tb-postgres"
    ports:
      - "8080:9090"
      - "1883:1883"
      - "7070:7070"
      - "5683-5688:5683-5688/udp"
    environment:
      TB_QUEUE_TYPE: in-memory
    volumes:
      - thingsboard-data:/data
      - thingsboard-logs:/var/log/thingsboard
volumes:
  thingsboard-data:
    external: true
  thingsboard-logs:
    external: true
``` 


> Step 4. Running the comands below: 

```bash
docker volume create thingsboard-data
docker volume create thingsboard-logs
docker-compose up -d 
```

> Step 5. Access the ThingsBoard web interface:

- System Administrator: sysadmin@thingsboard.org / sysadmin

- Tenant Administrator:  tenant@thingsboard.org / tenant

- Customer User: customer@thingsboard.org / customer


