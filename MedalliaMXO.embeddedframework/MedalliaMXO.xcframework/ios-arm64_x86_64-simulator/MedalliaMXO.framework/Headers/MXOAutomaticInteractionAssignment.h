//
//  MXOAutomaticInteractionAssignment.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOInteraction, UIViewController, MXOAutomaticInteractionAssignmentBuilder;

//=========================================
#pragma mark - Typedef
//=========================================

/*!
A block type used for building an ``MXOAutomaticInteractionAssignment`` object.
*/
typedef void (^MXOAutomaticInteractionAssignmentBuilderBlock)(MXOAutomaticInteractionAssignmentBuilder *builder);

//=========================================
#pragma mark - MXOAutomaticInteractionAssignment
//=========================================
/*!
Configuration object for assigning a custom Interaction path to a `UIViewController`.
 
## Properties
- `viewController`: The `UIViewController` instance to which an MXO Interaction path will be assigned.
- `interaction`: The MXO Interaction object to assign to the `UIViewController`.
 
## Examples
@TabNavigator {
 @Tab("Swift") {
 ```swift
 let interaction = MXOInteraction(withString: "/InteractionPath")
 MedalliaMXO.assign(automaticInteraction: MXOAutomaticInteractionAssignment { builder in
     builder.interaction = interaction
     builder.viewController = self
 })
 ```
 }
 @Tab("Objective-C") {
 ```objective-c
 NSError *error;
 __weak typeof(self) weakSelf = self;
 MXOInteraction *interaction = [MXOInteraction initWithString:@"/InteractionPath" error:&error];
 [MedalliaMXO assignAutomaticInteraction:[MXOAutomaticInteractionAssignment initWithBuilder:^(MXOAutomaticInteractionAssignmentBuilder * _Nonnull builder) {
     builder.interaction = interaction;
     builder.viewController = weakSelf;
 }] error:&error];
 ```
 }
}
*/
@interface MXOAutomaticInteractionAssignment : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The `UIViewController` instance to which an MXO Interaction path will be assigned.
*/
@property (nonatomic, weak, nullable, readonly) UIViewController *viewController;

/*!
The MXO Interaction object to assign to the `UIViewController`.
*/
@property (nonatomic, strong, nullable, readonly) MXOInteraction *interaction;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOAutomaticInteractionAssignment``.
 
## Returns
An instance of ``MXOAutomaticInteractionAssignmentBuilder``.
*/
- (MXOAutomaticInteractionAssignmentBuilder *)builder;

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOAutomaticInteractionAssignment`` using the provided `builder` block.
 
## Parameters
- `block`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(MXOAutomaticInteractionAssignmentBuilderBlock)block NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOAutomaticInteractionAssignmentBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOAutomaticInteractionAssignment`` objects.
 
## Properties
- `viewController`: The `UIViewController` instance to which an MXO Interaction path will be assigned.
- `interaction`: The MXO Interaction object to assign to the `UIViewController`.
*/
@interface MXOAutomaticInteractionAssignmentBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================
/*!
The `UIViewController` instance to which an MXO Interaction path will be assigned.
*/
@property (nonatomic, weak, nullable) UIViewController *viewController;

/*!
The MXO Interaction object to assign to the `UIViewController`.
*/
@property (nonatomic, strong, nullable) MXOInteraction *interaction;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates an ``MXOAutomaticInteractionAssignment`` object.
 
## Returns
An instance of ``MXOAutomaticInteractionAssignment``.
*/
- (MXOAutomaticInteractionAssignment *)build;

@end

NS_ASSUME_NONNULL_END
