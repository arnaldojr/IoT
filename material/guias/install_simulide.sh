#!/bin/bash

# Install SimulIDE electronic circuit simulator
APP_NAME=SimulIDE
APP_VERSION=0.4.14-SR4
APP_EXT=tar.gz
ARCH_TYPE=Lin64
FILE_NAME=${APP_NAME}_${APP_VERSION}_${ARCH_TYPE}
echo $FILE_NAME
sudo apt-get install -y libqt5serialport5
curl -o /tmp/${FILE_NAME}.${APP_EXT} -J -L https://mailfence.com/pub/docs/santigoro/web/${APP_NAME}_${APP_VERSION//-SR4/}/${FILE_NAME}.${APP_EXT}
cd /tmp
tar -xf /tmp/${FILE_NAME}.${APP_EXT}
sudo mkdir -p /opt/${APP_NAME,,}
sudo cp -R /tmp/${FILE_NAME}/* /opt/${APP_NAME,,}
cat > /tmp/${APP_NAME,,} << EOF
# /bin/sh
PATH=/opt/${APP_NAME,,}/bin:/opt/${APP_NAME,,}/share:$PATH; export PATH
/opt/${APP_NAME,,}/bin/${APP_NAME,,}
cd $HOME
EOF
sudo mv /tmp/${APP_NAME,,} /usr/local/bin
sudo chmod a+x /usr/local/bin/${APP_NAME,,}
cat > /tmp/${APP_NAME,,}.desktop << EOF
[Desktop Entry]
Name=${APP_NAME}
Comment=Electronic circuit emulator
GenericName=${APP_NAME}
Path=/opt/${APP_NAME,,}/bin
Exec=/opt/${APP_NAME,,}/bin/${APP_NAME,,}
Icon=/opt/${APP_NAME,,}/share/icons/hicolor/256x256/${APP_NAME,,}.png
Type=Application
StartupNotify=true
Terminal=false
Categories=Science;Electronics;
Keywords=Electronics;
EOF
sudo mv /tmp/${APP_NAME,,}.desktop /usr/share/applications/
cd $HOME
rm -rf /tmp/${APP_NAME,,}
