// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MedalliaMXO",
    platforms: [
            .iOS(.v11)
        ],
    products: [
        .library(
            name: "MedalliaMXO",
            targets: ["MedalliaMXO"]),
    ],
    targets: [
        .binaryTarget(
            name: "MedalliaMXO",
            path: "MedalliaMXO.embeddedframework/MedalliaMXO.xcframework"
        )
    ]
)
