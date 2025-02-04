# Hello World with [ThingsBoard](https://thingsboard.io/docs/paas/getting-started-guides/helloworld/#4-1-provision-device)

> Step 1. Access `ThingsBoard` with tenant login:


![step1](/projects/task-1/img/step1.png)

> Step 2. Access lateral navbar and click on `Entities` -> `Devices`:

![step2](/projects/task-1/img/step2.png)

> Step 3. Create a new `device` -> click on `Add new device`:

![step3](/projects/task-1/img/step3.png)

> Step 4. Filled all the required fields and click on `Next: Credentials`:

![step4](/projects/task-1/img/step4.png)

> Step 5. Add devide token:

![step5](/projects/task-1/img/step5.png)

> Step 6 & Step 7. Make request to device with `curl` on `Linux` or another available platform:

![step6](/projects/task-1/img/step6.png)

![step7](/projects/task-1/img/step7.png)


> Script for make request to device with `curl`:

```shell
#!/bin/sh
while true; do
    curl -v -X POST http://localhost:8080/api/v1/DEMO_DEVICE_TK/telemetry \
        --header "Content-Type: application/json" \
        --data '{"temperature": 25}'
    sleep 1
done
```

> Run:

```bash
./<file_name>.sh
```

- If necessary, assign permissions to the script: `chmod +x <file_name>`