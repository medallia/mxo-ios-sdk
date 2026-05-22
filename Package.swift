// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.
//  
//  Copyright © 2025 Medallia. Use subject to licensing terms.

import PackageDescription

// swift-tools-version:5.7
import PackageDescription

let package = Package(
    name: "medallia-mxo-ios-sdk",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "medallia-mxo-ios-sdk",
            targets: ["MedalliaMXOWrapper"]
        )
    ],
    dependencies: [
        .package(
            name: "medallia-mobile-bridge-ios-sdk",
            url: "https://github.com/medallia/mobile-ios-bridge-sdk.git",
            .upToNextMajor(from: "1.3.1")
        )
    ],
    targets: [
        .binaryTarget(
            name: "MedalliaMXO",
            path: "MedalliaMXO.embeddedframework/MedalliaMXO.xcframework"
        ),
        .target(
            name: "MedalliaMXOWrapper",
            dependencies: [
                .target(name: "MedalliaMXO"),
                .product(
                    name: "medallia-mobile-bridge-ios-sdk",
                    package: "medallia-mobile-bridge-ios-sdk"
                )
            ],
            path: "MedalliaMXOWrapper"
        )
    ]
)