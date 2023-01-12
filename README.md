![Medallia Experience Orchestration SDK](Distribution%20Supporting%20Files/images/MedalliaMXO_Logo.png)

## Table of Contents 

- [Prerequisites](#prerequisites)
- [Step 1: Add the Medallia Experience Orchestration SDK to your app](#step-1-add-the-medallia-experience-orchestration-sdk-to-your-app)
  * [CocoaPods](#cocoapods)
  * [Swift Package Manager](#swift-package-manager)
  * [Manual installation](#manual-installation)
- [Step 2: Configure biometric authentication](#step-2-configure-biometric-authentication)
- [Step 3: Configure the Medallia Experience Orchestration SDK for iOS](#step-3-configure-the-medallia-experience-orchestration-sdk-for-ios)
  * [Initialize the SDK](#initialize-the-sdk)
    + [Import the SDK’s module](#import-the-sdks-module)
    + [Set up the SDK in User mode for App Store builds](#set-up-the-sdk-in-user-mode-for-app-store-builds)
    + [Set up the SDK in Admin mode for internal distribution](#set-up-the-sdk-in-admin-mode-for-internal-distribution)
    + [Set up the SDK for SwiftUI app](#set-up-the-sdk-for-swiftui-app)
- [Additional integration considerations](#additional-integration-considerations)
  * [`ViewController`/`View` lifecycle overriding rules](#viewcontrollerview-lifecycle-overriding-rules)
  * [Sending Interaction requests based on the Interaction map](#sending-interaction-requests-based-on-the-interaction-map)
- [Additional features of Medallia Experience Orchestration SDK](#additional-features-of-medallia-experience-orchestration-sdk)
- [Troubleshooting guide](#troubleshooting-guide)
- [Questions or need help](#questions-or-need-help)
  * [Medallia Experience Orchestration support](#medallia-experience-orchestration-support)

For native integration, simply follow the steps outlined under the installation and configuration section to quickly integrate the SDK into your app. 

## Prerequisites

  - Install the following:
    
    * Xcode 14.0 or later

    * [CocoaPods](https://cocoapods.org) 1.10.0 or later

  - Make sure that your project meets these requirements:

    * Your project must target iOS 11 or later.

  - Set up a physical iOS device or use the iOS simulator to run your app.

## Step 1: Add the Medallia Experience Orchestration SDK to your app

We recommend using [CocoaPods](#cocoapods) to install the Medallia Experience Orchestration SDK. However, if you'd rather not use CocoaPods, you can integrate the SDK framework [directly](#manual-installation) or use [Swift Package Manager](#swift-package-manager) instead.

### CocoaPods

For integration via Cocoapods, please follow [Cocoapods Integration Guide](docs/cocoapods-integration-guide.md).

### Swift Package Manager

For integration via Swift Package Manager, please follow [SPM Integration Guide](docs/spm-integration-guide.md).

### Manual installation

For manual integration, please follow [Manual Integration Guide](docs/manual-integration-guide.md).

## Step 2: Configure biometric authentication

The SDK supports biometric authentication (Touch ID / Face ID) in Admin mode.

*Note:*
- To use Face ID authentication, you need to add:

```
<key>NSFaceIDUsageDescription</key>
<string>Why is my app authenticating using face id?</string>
```

to your `Info.plist` file. Failure to do so results in a dialog that tells the user your app has not provided the Face ID usage description.

## Step 3: Configure the Medallia Experience Orchestration SDK for iOS

Enable your app to automatically recognize **Interactions** in your app, by executing the following steps:

### Initialize the SDK

Complete the following steps to initialize the SDK.

#### Import the SDK’s module
1.    Open your App Delegate file.
2.    Add the following line at the top of the file below your own import statements:

    Swift:
    ```swift
    import MedalliaMXO
    ```

    Objective-C:
    ```objective-c
    @import MedalliaMXO;
    ```

#### Set up the SDK in User mode for App Store builds

To start tracking, capturing, and receiving Optimizations with the Medallia Experience Orchestration SDK in User mode, you must first initialize it with your Medallia Experience Orchestration API parameters. You can find your Medallia Experience Orchestration API parameters on the _API Credentials_ page.

For more information on finding these parameters, see [Find the Information required when Integrating Medallia Experience Orchestration with your Mobile Solutions](https://permalink.thunderhead.com/mobile-docs/mobile-integration-info).

With your parameters ready at hand, add the following lines to the top of the `didFinishLaunchingWithOptions`:

Swift:
```swift
MedalliaMXO.startSessionWithSK("ONE-XXXXXXXXXX-1022",
                           uri:"myAppsNameURI",
                        apiKey:"f713d44a-8af0-4e79-ba7e-xxxxxxxxxxxxxxxx",
                  sharedSecret:"bb8bacb2-ffc2-4c52-aaf4-xxxxxxxxxxxxxxxx",
                        userId:"api@yourCompanyName",
                     adminMode:false,
                      hostName:"eu2.thunderhead.com")
```


Objective-C:
```objective-c
[MedalliaMXO startSessionWithSK:@"ONE-XXXXXXXXXX-1022"
                            uri:@"myAppsNameURI"
                         apiKey:@"f713d44a-8af0-4e79-ba7e-xxxxxxxxxxxxxxxx"
                   sharedSecret:@"bb8bacb2-ffc2-4c52-aaf4-xxxxxxxxxxxxxxxx"
                         userId:@"api@yourCompanyName"
                      adminMode:NO
                       hostName:@"eu2.thunderhead.com"];
```

#### Set up the SDK in Admin mode for internal distribution

We recommend adding the Admin mode function on your internal builds, behind a debug settings function or on a dedicated build pipeline, as described [here](https://permalink.thunderhead.com/mobile-docs/mobile-admin-mode-integration).

To use the framework in Admin mode, simply change the `adminMode` boolean to `true`, as follows:

Swift:
```swift
MedalliaMXO.startSessionWithSK("ONE-XXXXXXXXXX-1022",
                           uri:"myAppsNameURI",
                        apiKey:"f713d44a-8af0-4e79-ba7e-xxxxxxxxxxxxxxxx",
                  sharedSecret:"bb8bacb2-ffc2-4c52-aaf4-xxxxxxxxxxxxxxxx",
                        userId:"api@yourCompanyName",
                     adminMode:true,
                      hostName:"eu2.thunderhead.com")
```


Objective-C:
```objective-c
[MedalliaMXO startSessionWithSK:@"ONE-XXXXXXXXXX-1022"
                            uri:@"myAppsNameURI"
                         apiKey:@"f713d44a-8af0-4e79-ba7e-xxxxxxxxxxxxxxxx"
                   sharedSecret:@"bb8bacb2-ffc2-4c52-aaf4-xxxxxxxxxxxxxxxx"
                         userId:@"api@yourCompanyName"
                      adminMode:YES
                       hostName:@"eu2.thunderhead.com"];
```

*Note:*
- Dynamic configuration of both Admin and User mode is supported.

#### Set up the SDK for SwiftUI app

When configuring the SDK in SwiftUI, in order to capture all lifecycle events, it is a recommended best practice to initialize the SDK in the `didFinishLaunchingWithOptions` method of `AppDelegate` class. If the SwiftUI app doesn't have an `AppDelegate` class, use the following code to create an `AppDelegate` class and initialize the SDK:

```swift
class AppDelegate: NSObject, UIApplicationDelegate {
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey : Any]? = nil) -> Bool {
        MedalliaMXO.startSessionWithSK("ONE-XXXXXXXXXX-1022",
                                   uri:"myAppsNameURI",
                                apiKey:"f713d44a-8af0-4e79-ba7e-xxxxxxxxxxxxxxxx",
                          sharedSecret:"bb8bacb2-ffc2-4c52-aaf4-xxxxxxxxxxxxxxxx",
                                userId:"api@yourCompanyName",
                             adminMode:true,
                              hostName:"eu2.thunderhead.com")
        return true
    }
}
```

Once the `AppDelegate` class is created and the SDK is initialized, now in the `App` scene, use the `UIApplicationDelegateAdaptor` property wrapper to tell SwiftUI it should use the `AppDelegate` class for the application delegate.

```swift
@main
struct SwiftUIApp: App {
    @UIApplicationDelegateAdaptor(AppDelegate.self) var appDelegate

    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}
```

**You have now successfully integrated the Medallia Experience Orchestration SDK for iOS.**

## Additional integration considerations

### `ViewController`/`View` lifecycle overriding rules

The framework listens to a number of `UIViewController` and `UIView` methods to provide the desired functionality. Those methods are:
- `viewWillAppear`
- `viewDidAppear`
- `viewWillDisappear`
- `didMoveToWindow`

If you use these methods in your code, please ensure to call super when implementing them.

### Sending Interaction requests based on the Interaction map

In order to reduce the number of unnecessary Interaction requests sent automatically by the SDK, only Interactions with explicit Interaction paths created under a Touchpoint and configured with at least one point are sent to Medallia Experience Orchestration.

*Note:*
- The SDK will only send Interactions if they have been created under a Touchpoint and/or if they match wildcard rules defined under a Touchpoint.
- For an Interaction to be sent by the SDK this Interaction needs to contain at least one Activity Capture Point, Attribute Capture Point, and/or Optimization Point.
- If you are running the SDK in [User mode](#set-up-the-sdk-in-user-mode-for-app-store-builds), you need to ensure that all Interactions and related points have been fully published, before the SDK will trigger a request.

## Additional features of Medallia Experience Orchestration SDK

For additional features of Medallia Experience Orchestration SDK, please follow [Additional Features Guide](docs/additional-features-guide.md).

## Troubleshooting guide

Having trouble with Medallia Experience Orchestration in your iOS project? Visit the [Troubleshooting Guide](../TROUBLESHOOTING-GUIDE.md)

## Questions or need help

### Medallia Experience Orchestration support
_For Medallia Experience Orchestration questions, please submit a support ticket via https://support.thunderhead.com_.
