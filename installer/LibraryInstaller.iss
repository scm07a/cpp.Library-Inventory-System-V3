; ======================================================
; Library Inventory Manager v3.0.0
; Developed by Mohamed Mourad
; ======================================================

#define MyAppName "Library Inventory Manager"
#define MyAppVersion "3.0.0"
#define MyAppPublisher "Mohamed Mourad"
#define MyAppURL "https://github.com/scm07a/Library-V3"
#define MyAppExeName "LibraryV3.exe"
[Setup]

VersionInfoVersion={#MyAppVersion}
VersionInfoCompany={#MyAppPublisher}
VersionInfoDescription=Library Inventory Manager
VersionInfoCopyright=© Mohamed Mourad
AppId={{1161F470-66D0-4109-9A4D-FE5210E3E4B9}

AppName={#MyAppName}
AppVersion={#MyAppVersion}

AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}

DefaultDirName={autopf}\{#MyAppName}
DefaultGroupName={#MyAppName}

ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible

PrivilegesRequired=admin

DisableProgramGroupPage=no

Compression=lzma2
SolidCompression=yes

WizardStyle=modern dark

OutputDir=Output
OutputBaseFilename=LibraryInventoryManagerSetup_v3.0.0

SetupIconFile=E:\Personal Projects\C++ Code Editor\Library V3\assets\library.ico

UninstallDisplayIcon={app}\{#MyAppExeName}

[Languages]

Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]

Name: "desktopicon"; Description: "Create Desktop Shortcut"; Flags: unchecked

[Files]

Source: "E:\Personal Projects\C++ Code Editor\Library V3\build\LibraryV3.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "E:\Personal Projects\C++ Code Editor\Library V3\assets\library.ico"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\msys64\ucrt64\bin\libgcc_s_seh-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\msys64\ucrt64\bin\libstdc++-6.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\msys64\ucrt64\bin\libwinpthread-1.dll"; DestDir: "{app}"; Flags: ignoreversion

[Icons]

Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\Uninstall {#MyAppName}"; Filename: "{uninstallexe}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]

Filename: "{app}\{#MyAppExeName}"; \
Description: "Launch {#MyAppName}"; \
Flags: nowait postinstall skipifsilent