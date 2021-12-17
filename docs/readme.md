# Documentation

This file will contain the basic information to install and run the project.

## Installing Services

All the applications that need to be up and running when the Raspberry Pi is booted up can be transformed into services. This means that the operating system will manage their execution through the `systemd` manager. In order to do so, we need to follow several steps.

1. Identify the service file
  * Ex: myapp.service
2. Copy it to one of the Systemd locations: `sudo cp /path/to/service/myapp.service /usr/lib/systemd/system`
3. Register it with the ooperating system: `sudo systemctl enable myapp.service`
4. Start the service: `sudo systemctl start myapp.service`

To check on the status of the service: `systemctl status myapp.service`

To check the logs of the service: `journalctl -u myapp.service`

To stop the service: `sudo systemctl stop myapp.service`

To remove the service: `sudo systemctl disable myapp.service`

### List of Services

The following applications will have to run as services:

* myapp, this is the server that handles data storage and retrieval
