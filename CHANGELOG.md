#### Version 1.2.1
* [UPDATE] Added Privacy Manifests based on [Apple requirements](https://developer.apple.com/documentation/bundleresources/privacy_manifest_files).
* [UPDATE] Updated minimum deployment target to iOS 12.0.

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

