## CocoaPods

Make sure you have the [CocoaPods](https://cocoapods.org) dependency manager installed. You can do so by executing the following command:

```sh
$ gem install cocoapods
```

1. Create a Podfile if you don't already have one:

```sh
$ cd your-project-directory
```

```sh
$ pod init
```

2. To your Podfile, add the *Medallia Experience Orchestration SDK* pod that you want to use in your app.

```txt
# Medallia Experience Orchestration SDK
    target :YourTargetName do
    pod 'MedalliaMXO', '~> {SDK_VERSION}'
    end
```

3. Install the pods, then open your `.xcworkspace` file to see the project in Xcode:

```sh
$ pod install
```

```sh
$ open your-project.xcworkspace
```

You can find an example project for pod installation [here](https://permalink.thunderhead.com/mobile-ios/dynamic-initialization-example).

*Note:*
- While running `pod install`, if you get the following warnings:

```txt
[!] The `MedalliaMXOSampleApp [Debug]` target overrides the `OTHER_LDFLAGS` build setting defined in `Pods/Target Support Files/Pods-MedalliaMXOSampleApp/Pods-MedalliaMXOSampleApp.debug.xcconfig'. This can lead to problems with the CocoaPods installation
    - Use the `$(inherited)` flag, or
    - Remove the build settings from the target.
[!] The `MedalliaMXOSampleApp [Release]` target overrides the `OTHER_LDFLAGS` build setting defined in `Pods/Target Support Files/Pods-MedalliaMXOSampleApp/Pods-MedalliaMXOSampleApp.release.xcconfig'. This can lead to problems with the CocoaPods installation
    - Use the `$(inherited)` flag, or
    - Remove the build settings from the target.
```

Go to app target's **Build Settings**, add **$(inherited)** to **Other Linker Flags**, which will add linker flags generated in pods or see our [Troubleshooting Guide](../TROUBLESHOOTING-GUIDE.md#resolve-undefined-symbols-for-architecture-arm64-compile-time-error).

[Step 2: Configure biometric authentication](../README.md#step-2-configure-biometric-authentication)