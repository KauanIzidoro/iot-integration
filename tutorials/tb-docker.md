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
```

> Step 3. Running the comands below: 

```bash
docker volume create thingsboard-data
docker volume create thingsboard-logs
docker-compose up -d 
```

> Step 4. Access the ThingsBoard web interface:

- System Administrator: sysadmin@thingsboard.org / sysadmin

- Tenant Administrator:  tenant@thingsboard.org / tenant

- Customer User: customer@thingsboard.org / customer


