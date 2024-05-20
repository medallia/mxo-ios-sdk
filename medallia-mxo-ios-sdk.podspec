#  
#  Copyright © 2023 Medallia. Use subject to licensing terms.
#
#
# Be sure to run `pod lib lint medallia-mxo-ios-sdk.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name                = "medallia-mxo-ios-sdk"
  s.version             = "2.1.0-pre-alpha.0"
  s.summary             = "The MedalliaMXO SDK for iOS."
  s.authors             = { "Medallia" => "cocoapods-mxo@medallia.com" }
  s.homepage            = "https://github.com/medallia/mxo-ios-sdk"
  s.description         = "The MedalliaMXO SDK for iOS. The SDK supports iOS 12.0 and above."
  s.license             = { :type => "Commercial", :text => "Copyright © 2023 Medallia. Use subject to licensing terms." }
  s.frameworks          = ["Accelerate", "CoreLocation", "Foundation", "LocalAuthentication", "CoreGraphics", "MessageUI", "SafariServices", "Security", "SystemConfiguration", "UIKit", "WebKit"]
  s.library             = "sqlite3"
  s.source              = { :git => "https://github.com/medallia/mxo-ios-sdk.git", :tag => "#{s.version}" }
  s.platform            = :ios, "12.0"
  s.default_subspec     = 'Core'
  s.subspec 'Core' do |core|
    core.preserve_paths      = 'MedalliaMXO.embeddedframework/MedalliaMXO.xcframework'
    core.vendored_frameworks = 'MedalliaMXO.embeddedframework/MedalliaMXO.xcframework'
    core.resources           = 'MedalliaMXO.embeddedframework/MedalliaMXOBundle.bundle'
  end
end
