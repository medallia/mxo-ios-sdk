// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "medallia-mxo-ios-sdk",
    platforms: [
            .iOS(.v11)
        ],
    products: [
        .library(
            name: "medallia-mxo-ios-sdk",
            targets: ["medallia-mxo-ios-sdk"]),
    ],
    targets: [
        .binaryTarget(
            name: "medallia-mxo-ios-sdk",
            path: "MedalliaMXO.embeddedframework/MedalliaMXO.xcframework"
        )
    ]
)
