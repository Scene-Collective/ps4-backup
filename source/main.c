#include "ps4.h"

int _main(struct thread *td) {
  UNUSED(td);

  initKernel();
  initLibc();

  jailbreak();

  initSysUtil();

  FILE *usbdir = fopen("/mnt/usb0/.dirtest", "w");
  if (!usbdir) {
    usbdir = fopen("/mnt/usb1/.dirtest", "w");
    if (!usbdir) {
      copy_file("/system_data/priv/mms/app.db", "/system_data/priv/mms/app.bak");
      copy_file("/system_data/priv/mms/addcont.db", "/system_data/priv/mms/addcont.bak");
      copy_file("/system_data/priv/mms/av_content_bg.db", "/system_data/priv/mms/av_content_bg.bak");
      copy_file("/user/system/webkit/secure/appcache/ApplicationCache.db", "/user/system/webkit/secure/appcache/ApplicationCache.bak");
      copy_file("/user/system/webkit/webbrowser/appcache/ApplicationCache.db", "/user/system/webkit/webbrowser/appcache/ApplicationCache.bak");
      printf_notification("Internal backup complete.\nThis was only a database backup, use a USB device for a full backup.");
    } else {
      fclose(usbdir);
      printf_notification("Backing up to USB1");
      unlink("/mnt/usb1/.dirtest");
      mkdir("/mnt/usb1/DB_Backup/", 0777);
      copy_file("/system_data/priv/mms/app.db", "/mnt/usb1/DB_Backup/app.db");
      copy_file("/system_data/priv/mms/addcont.db", "/mnt/usb1/DB_Backup/addcont.db");
      copy_file("/system_data/priv/mms/av_content_bg.db", "/mnt/usb1/DB_Backup/av_content_bg.db");
      mkdir("/mnt/usb1/UserData/", 0777);
      mkdir("/mnt/usb1/UserData/system_data/", 0777);
      mkdir("/mnt/usb1/UserData/system_data/savedata", 0777);
      mkdir("/mnt/usb1/UserData/system_data/priv", 0777);
      mkdir("/mnt/usb1/UserData/system_data/priv/home", 0777);
      mkdir("/mnt/usb1/UserData/system_data/priv/license", 0777);
      mkdir("/mnt/usb1/UserData/system_data/priv/activation", 0777);
      mkdir("/mnt/usb1/UserData/user/", 0777);
      mkdir("/mnt/usb1/UserData/user/home/", 0777);
      mkdir("/mnt/usb1/UserData/user/trophy", 0777);
      mkdir("/mnt/usb1/UserData/user/license", 0777);
      mkdir("/mnt/usb1/UserData/user/settings", 0777);
      mkdir("/mnt/usb1/UserData/user/system", 0777);
      mkdir("/mnt/usb1/UserData/user/system/webkit", 0777);
      mkdir("/mnt/usb1/UserData/user/system/webkit/secure", 0777);
      mkdir("/mnt/usb1/UserData/user/system/webkit/webbrowser", 0777);
      printf_notification("Copying user data\nPlease wait...");
      copy_dir("/system_data/savedata", "/mnt/usb1/UserData/system_data/savedata");
      copy_dir("/user/home", "/mnt/usb1/UserData/user/home");
      copy_dir("/user/trophy", "/mnt/usb1/UserData/user/trophy");
      copy_dir("/user/license", "/mnt/usb1/UserData/user/license");
      copy_dir("/user/settings", "/mnt/usb1/UserData/user/settings");
      copy_dir("/user/system/webkit/secure", "/mnt/usb1/UserData/user/system/webkit/secure");
      copy_dir("/user/system/webkit/webbrowser", "/mnt/usb1/UserData/user/system/webkit/webbrowser");
      copy_dir("/system_data/priv/home", "/mnt/usb1/UserData/system_data/priv/home");
      copy_dir("/system_data/priv/license", "/mnt/usb1/UserData/system_data/priv/license");
      copy_dir("/system_data/priv/activation", "/mnt/usb1/UserData/system_data/priv/activation");
      printf_notification("USB backup complete!");
    }
  } else {
    fclose(usbdir);
    printf_notification("Backing up to USB0");
    unlink("/mnt/usb0/.dirtest");
    mkdir("/mnt/usb0/DB_Backup/", 0777);
    copy_file("/system_data/priv/mms/app.db", "/mnt/usb0/DB_Backup/app.db");
    copy_file("/system_data/priv/mms/addcont.db", "/mnt/usb0/DB_Backup/addcont.db");
    copy_file("/system_data/priv/mms/av_content_bg.db", "/mnt/usb0/DB_Backup/av_content_bg.db");
    mkdir("/mnt/usb0/UserData/", 0777);
    mkdir("/mnt/usb0/UserData/system_data/", 0777);
    mkdir("/mnt/usb0/UserData/system_data/savedata", 0777);
    mkdir("/mnt/usb0/UserData/system_data/priv", 0777);
    mkdir("/mnt/usb0/UserData/system_data/priv/home", 0777);
    mkdir("/mnt/usb0/UserData/system_data/priv/license", 0777);
    mkdir("/mnt/usb0/UserData/system_data/priv/activation", 0777);
    mkdir("/mnt/usb0/UserData/user/", 0777);
    mkdir("/mnt/usb0/UserData/user/home/", 0777);
    mkdir("/mnt/usb0/UserData/user/trophy", 0777);
    mkdir("/mnt/usb0/UserData/user/license", 0777);
    mkdir("/mnt/usb0/UserData/user/settings", 0777);
    mkdir("/mnt/usb0/UserData/user/system", 0777);
    mkdir("/mnt/usb0/UserData/user/system/webkit", 0777);
    mkdir("/mnt/usb0/UserData/user/system/webkit/secure", 0777);
    mkdir("/mnt/usb0/UserData/user/system/webkit/webbrowser", 0777);
    printf_notification("Copying user data\nPlease wait...");
    copy_dir("/system_data/savedata", "/mnt/usb0/UserData/system_data/savedata");
    copy_dir("/user/home", "/mnt/usb0/UserData/user/home");
    copy_dir("/user/trophy", "/mnt/usb0/UserData/user/trophy");
    copy_dir("/user/license", "/mnt/usb0/UserData/user/license");
    copy_dir("/user/settings", "/mnt/usb0/UserData/user/settings");
    copy_dir("/user/system/webkit/secure", "/mnt/usb0/UserData/user/system/webkit/secure");
    copy_dir("/user/system/webkit/webbrowser", "/mnt/usb0/UserData/user/system/webkit/webbrowser");
    copy_dir("/system_data/priv/home", "/mnt/usb0/UserData/system_data/priv/home");
    copy_dir("/system_data/priv/license", "/mnt/usb0/UserData/system_data/priv/license");
    copy_dir("/system_data/priv/activation", "/mnt/usb0/UserData/system_data/priv/activation");
    printf_notification("USB backup complete!");
  }

  return 0;
}
