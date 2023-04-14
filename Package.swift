// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.
//  
//  Copyright © 2023 Medallia. Use subject to licensing terms.

import PackageDescription

let package = Package(
    name: "medallia-mxo-ios-sdk",
    platforms: [
            .iOS(.v11)
        ],
    products: [
        .library(
            name: "medallia-mxo-ios-sdk",
            targets: ["MedalliaMXO"]),
    ],
    targets: [
        .binaryTarget(
            name: "MedalliaMXO",
            path: "MedalliaMXO.embeddedframework/MedalliaMXO.xcframework"
        )
    ]
)
