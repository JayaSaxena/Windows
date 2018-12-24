using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Win32;

namespace RegistryTest
{
    class Program
    {
        static void Main(string[] args)
         {

             WriteKey(RegistryView.Registry32, "32bit");
             WriteKey(RegistryView.Registry64, "64bit");
            
             WriteKey(RegistryView.Registry32, "Software\\32bit");
             WriteKey(RegistryView.Registry64, "Software\\64bit");


             WriteKey(RegistryView.Registry32, "Software\\Classes\\32bit");
             WriteKey(RegistryView.Registry64, "Software\\Classes\\64bit");

             WriteKey(RegistryView.Registry32, "Software\\Classes\\AppID\\32bit");
             WriteKey(RegistryView.Registry64, "Software\\Classes\\AppID\\64bit");
             
             WriteKey(RegistryView.Registry32, "Software\\Classes\\CLSID\\32bit");
             WriteKey(RegistryView.Registry64, "Software\\Classes\\CLSID\\64bit");

             WriteKey(RegistryView.Registry32, "Software\\Classes\\Interface\\32bit");
             WriteKey(RegistryView.Registry64, "Software\\Classes\\Interface\\64bit");

            //RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry32).CreateSubKey("32bit"); //Not Allowed
            RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, ReistryView.Registry32).CreateSubKey("Software\\32bit");
            RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry32).CreateSubKey("Software\\Classes\\32bit");
             RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry32).CreateSubKey("Software\\Classes\\Appid\\32bit");
             RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry32).CreateSubKey("Software\\Classes\\CLSID\\32bit");
             RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry32).CreateSubKey("Software\\Classes\\DirectShow\\32bit");

             RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry64).CreateSubKey("Software\\64bit");
             RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry64).CreateSubKey("Software\\Classes\\64bit");
             RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry64).CreateSubKey("Software\\Classes\\Appid\\64bit");
             RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry64).CreateSubKey("Software\\Classes\\CLSID\\64bit");
             RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry64).CreateSubKey("Software\\Classes\\DirectShow\\64bit");


            //Console.WriteLine(RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry32).ToString());
            //Console.ReadKey();
        }

         private static void WriteKey(RegistryView registryView, string path)
         {
             RegistryKey.OpenBaseKey(RegistryHive.CurrentUser, registryView).CreateSubKey(path);
         }
    
    }
}
