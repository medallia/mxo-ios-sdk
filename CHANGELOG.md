#### Version 3.1.1
* [BUGFIX] Fixed a crash in SwiftUI Previews where `MedalliaMXOBundle` could not be found within the Preview's sandboxed environment.

#### Version 3.1.0
* [NEW] Added support for using the optimization image's `alt-text` to improve accessibility.

#### Version 3.0.2
* [BUGFIX] Fixed a crash in `WKWebView` caused by observing its URL property on iOS versions 18.4+.

#### Version 3.0.1
* [BUGFIX] Fixed an issue where incorrect information about App name and App version was sent.

#### Version 3.0.0
* [BREAKING] Added support for using the MXO SDK with Xcode 16.2. The MXO SDK requires Xcode 16+ (iOS 18). Please see our known issues [online documentation](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-known-issues).
* [BREAKING] Updated minimum deployment target to iOS 13.0.
* [BREAKING] Upgraded Swift version from 5 to 6.
* [NEW] Added Bridge functionality for communication between other Medallia SDKs. For further details on this, see our [online documentation](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-additional-integrations).
* [NEW] Added ability to include an Interaction back for tracking if it was excluded from Interaction tracking previously. For further details on this, see our [online documentation](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-including-interaction).
* [UPDATE] Updated the Apple Privacy Manifest with a required keys.
* [BUGFIX] Fixed an issue with full screen optimizations where tapping outside an image was sending a positive response.
* [BUGFIX] Fixed an issue with identity transfer logic where an `mxo-click` interaction was not properly sent.
* [BUGFIX] Fixed an issue where an app preference path was not properly retrieved.
* [BUGFIX] Fixed an issue where an Attribute Capture Point could be saved with an invalid name.

#### Version 2.0.3
* [UPDATE] Added a distribution certificate for signing the MXO SDK to support the latest app code signing standards from Apple.

#### Version 2.0.2
* [BUGFIX] Fixed an issue with the Apple Privacy Manifest missing a required key.

#### Version 2.0.1
* [BUGFIX] Fixed a crash caused by a `null` pointer dereference within `objc_setAssociatedObject`, triggered from `OneRuntimeAPIAgent` during offline Interaction processes.

#### Version 2.0.0
* [BREAKING] Added support for using the MXO SDK with Xcode 15.2. The MXO SDK requires Xcode 15+ (iOS 17).
* [BREAKING] Updated minimum deployment target to iOS 12.0.
* [BREAKING] Removed `OAuth1` from runtime requests. Refer to our [migration guide](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-migration-v2.0.0) for detailed information.
* [BREAKING] Removed the `allTracking` opt-in option from the opt-out configuration. Refer to our [migration guide](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-migration-v2.0.0) for detailed information.
* [BREAKING] Fixed an issue with Interaction path differences between iOS versions for SwiftUI apps. Refer to our [migration guide](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-migration-v2.0.0) for detailed information.
* [NEW] Added Privacy Manifests based on [Apple requirements](https://developer.apple.com/documentation/bundleresources/privacy_manifest_files).
* [UPDATE] Updated `one-tid` to `tid` query param appended to an outgoing URL.
* [UPDATE] Updated Admin User Interface.
* [UPDATE] Updated opt-out configuration logging messages.
* [BUGFIX] Fixed an issue where `WebView` was not properly recognized as an Interaction.
* [BUGFIX] Fixed an issue where updating Customer Attributes, Activity Types, and Propositions in an MXO Space did not reflect those changes in the SDK.

#### Version 2.0.0-alpha.0
* [UPDATE] Hybrid Logging Updates.

#### Version 2.0.0-pre-alpha.0
* [UPDATE] Updated Admin User Interface.
* [BUGFIX] Fixed a request conflict that was occurring due to an invalid Interaction path being generated from local files.
* [BUGFIX] Fixed an issue with background Interaction window tracking.

#### Version 1.3.0-pre-alpha.3
* [UPDATE] Updated the SDK to use the latest Designtime APIs for creating Interactions.
* [UPDATE] Updated Admin User Interface.
* [BUGFIX] Fixed an issue with an untappable button on the empty search results screen.
* [BUGFIX] Fixed an issue where some Interactions were sent twice.
* [BUGFIX] Fixed an issue where a Digital Form was not recognized as an Interaction.

#### Version 1.2.0
* [UPDATE] Removed `OAuth1` from runtime requests. For further details on this see our [migration guide](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-migration-v1.2.0).
* [BUGFIX] Fixed an issue with a Navigation Bar label's path mismatch across iOS versions.
* [BUGFIX] Fixed an issue where optimization was not returned for `PageViewController` in a SwiftUI app.
* [BUGFIX] Fixed an issue where a user with no permissions was not getting an error message in Admin mode.
* [BUGFIX] Fixed an issue with `clearTid` API where it was clearing user credentials along with TIDs.

#### Version 1.1.3
* [BUGFIX] Fixed an issue with `contentUrl` not being returned in `MXOAsset` for external assets.
* [BUGFIX] Fixed an issue with `MXOAssetResponse` not returning `label`, `target`, and `targetUrl`.
* [BUGFIX] Fixed an issue with `MXOCaptureAttributePoint` not returning `capturePhase`, `captureType`, `captureDelay`, `elementType`, `elementName`, and `elementAttributeName`.

#### Version 1.1.2
* [BUGFIX] Fixed an issue with `directives` not being returned in `MXOOptimizationPoint`.
* [BUGFIX] Fixed an issue when a scheme was appended to a Touchpoint URI when not set by a developer.

#### Version 1.1.1
* [BUGFIX] Fixed an issue parsing the response from an Interaction.

#### Version 1.1.0
* [UPDATE] Telemetry updates.

#### Version 1.0.1
* [BUGFIX] Fixed an Umbrella Header warning for MedalliaMXOConfiguration.h.

#### Version 1.0.0
* [BREAKING] Added support for using the MXO SDK with Xcode 14.2. The MXO SDK requires Xcode 14+ (iOS 16).
* [BREAKING] Updated minimum deployment target to iOS 11.0.
* [BREAKING] Updated the SDK's public APIs. For further details on this see our [online documentation](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-features). If migrating from Thunderhead SDK, please visit our [migration guide](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-migration-api).
* [BREAKING] Updated prebuilt Interactions. If migrating from Thunderhead SDK, please visit our [migration guide](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-migration-prebuilt).
* [NEW] Added support for SwiftUI apps. For further details on this see our [online documentation](https://docs.medallia.com/en/medallia-experience-orchestration/orchestration-for-ios/configure-the-mxo-sdk-for-ios#task-6504--en__SwiftUI_Initialization). To see known SwiftUI issues, please visit our [troubleshooting guide](https://docs.medallia.com/en/?resourceId=mxo-ios-sdk-troubleshooting-swiftui).
* [UPDATE] Security updates.
* [BUGFIX] Fixed an issue where a trailing slash on host was breaking the SDK.

