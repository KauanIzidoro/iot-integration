#!/bin/sh
while true; do
    curl -v -X POST http://localhost:8080/api/v1/DEMO_DEVICE_TK/telemetry \
        --header "Content-Type: application/json" \
        --data '{"temperature": 25}'
    sleep 1
done