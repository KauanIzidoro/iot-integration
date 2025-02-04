#!/bin/sh
while true; do
    TEMP=$(awk -v min=20 -v max=30 'BEGIN{srand(); print min+rand()*(max-min)}')
    curl -v -X POST http://localhost:8080/api/v1/DEMO_DEVICE_TK/telemetry \
        --header "Content-Type: application/json" \
        --data "{\"temperature\": $TEMP}"
    sleep 1
done
