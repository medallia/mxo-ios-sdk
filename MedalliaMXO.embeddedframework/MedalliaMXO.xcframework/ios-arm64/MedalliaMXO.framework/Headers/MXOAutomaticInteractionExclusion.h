//
//  MXOAutomaticInteractionExclusion.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UIViewController, MXOAutomaticInteractionExclusionBuilder;

//=========================================
#pragma mark - Typedef
//=========================================

/*!
A block type used for building an ``MXOAutomaticInteractionExclusion`` object.
*/
typedef void (^MXOAutomaticInteractionExclusionBuilderBlock)(MXOAutomaticInteractionExclusionBuilder *builder);

/*!
The configuration object used to exclude an automatic Interaction.
 
## Properties
- `viewController`: The `UIViewController` instance to be excluded from Interaction tracking.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 MedalliaMXO.exclude(automaticInteraction: MXOAutomaticInteractionExclusion { builder in
     builder.viewController = self
 })
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 __weak typeof(self) weakSelf = self;
 [MedalliaMXO excludeAutomaticInteraction:[MXOAutomaticInteractionExclusion initWithBuilder:^(MXOAutomaticInteractionExclusionBuilder * _Nonnull builder) {
     builder.viewController = weakSelf;
 }] error:&error];
 ```
 }
}
*/
@interface MXOAutomaticInteractionExclusion : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The `UIViewController` instance to be excluded from Interaction tracking.
*/
@property (nonatomic, weak, nullable, readonly) UIViewController *viewController;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOAutomaticInteractionExclusion``.
 
## Returns
An instance of ``MXOAutomaticInteractionExclusionBuilder``.
*/
- (MXOAutomaticInteractionExclusionBuilder *)builder;

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOAutomaticInteractionExclusion`` using the provided `builder` block.
 
## Parameters
- `block`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(MXOAutomaticInteractionExclusionBuilderBlock)block NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOAutomaticInteractionExclusionBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOAutomaticInteractionExclusion`` objects.
 
## Properties
- `viewController`: The `UIViewController` to exclude from Interaction tracking.
*/
@interface MXOAutomaticInteractionExclusionBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================
/*!
The `UIViewController` instance to be excluded from Interaction tracking.
*/
@property (nonatomic, weak, nullable) UIViewController *viewController;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates an ``MXOAutomaticInteractionExclusion`` object.
 
## Returns
An instance of ``MXOAutomaticInteractionExclusion``.
*/
- (MXOAutomaticInteractionExclusion *)build;

@end

NS_ASSUME_NONNULL_END
