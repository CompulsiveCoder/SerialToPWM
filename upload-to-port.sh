echo "Uploading to port /dev/$1"

pio run --target upload --environment uno --upload-port /dev/$1
