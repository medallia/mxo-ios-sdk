//
//  MXOAutomaticInteractionInclusion.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UIViewController, MXOAutomaticInteractionInclusionBuilder;

//=========================================
#pragma mark - Typedef
//=========================================

/*!
A block type used for building an ``MXOAutomaticInteractionInclusion`` object.
*/
typedef void (^MXOAutomaticInteractionInclusionBuilderBlock)(MXOAutomaticInteractionInclusionBuilder *builder);

/*!
The configuration object used to include an automatic Interaction.
 
## Properties
- `viewController`: The `UIViewController` to include for Interaction tracking.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.include(automaticInteraction: MXOAutomaticInteractionInclusion { builder in
     builder.viewController = self
 })
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 __weak typeof(self) weakSelf = self;
 [MedalliaMXO includeAutomaticInteraction:[MXOAutomaticInteractionInclusion initWithBuilder:^(MXOAutomaticInteractionInclusionBuilder * _Nonnull builder) {
     builder.viewController = weakSelf;
 }] error:&error];
 ```
 }
}
*/
@interface MXOAutomaticInteractionInclusion : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The `UIViewController` to include for Interaction tracking.
*/
@property (nonatomic, weak, nullable, readonly) UIViewController *viewController;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOAutomaticInteractionInclusion``.
 
## Returns
An instance of ``MXOAutomaticInteractionInclusionBuilder``.
*/
- (MXOAutomaticInteractionInclusionBuilder *)builder;

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOAutomaticInteractionInclusion`` using the provided `builder` block.
 
## Parameters
- `block`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(MXOAutomaticInteractionInclusionBuilderBlock)block NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOAutomaticInteractionInclusionBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOAutomaticInteractionInclusion`` objects.
 
## Properties
- `viewController`: The `UIViewController` to include for Interaction tracking.
*/
@interface MXOAutomaticInteractionInclusionBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================
/*!
The `UIViewController` to include for Interaction tracking.
*/
@property (nonatomic, weak, nullable) UIViewController *viewController;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates an ``MXOAutomaticInteractionInclusion`` object.
 
## Returns
An instance of ``MXOAutomaticInteractionInclusion``.
*/
- (MXOAutomaticInteractionInclusion *)build;

@end

NS_ASSUME_NONNULL_END
