//----------------------------------------------------------------------------------------------------//
//-------------------------------------SETUP---------------------------------------------------------//
/*


        rm -rf ~/libdatachannel
        git clone --recursive https://github.com/paullouisageneau/libdatachannel.git
git config --global http.postBuffer 524288000

        cd libdatachannel
        git submodule update --init --recursive
        cd libdatachannel
        mkdir build
        cd build
        cmake ..
        make
        sudo make install


    ls /usr/local/lib | grep libdatachannel
pkg-config --list-all | grep libdatachannel



cd /usr/local/lib/pkgconfig/
Create a new .pc file named libdatachannel.pc and add the following contents:

prefix=/usr/local
exec_prefix=${prefix}
libdir=${exec_prefix}/lib
includedir=${prefix}/include

Name: libdatachannel
Description: WebRTC data channels
Version: 0.14.0
Libs: -L${libdir} -ldatachannel
Cflags: -I${includedir}/rtc


Save the .pc File:

Save the file and make sure the permissions are set correctly:
sudo chmod 644 libdatachannel.pc


Register with pkg-config
After creating or updating the .pc file, register it with pkg-config:

sh
Copy code
pkg-config --add libdatachannel /usr/local/lib/pkgconfig/libdatachannel.pc
Verify with pkg-config
Finally, verify that pkg-config can now find libdatachannel:

sh
Copy code
pkg-config --list-all | grep libdatachannel
You should see an output similar to:

kotlin
Copy code
libdatachannel - WebRTC data channels


ls /usr/local/lib/pkgconfig/libdatachannel.pc
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH


*/
//----------------------------------------------------------------------------------------------------//