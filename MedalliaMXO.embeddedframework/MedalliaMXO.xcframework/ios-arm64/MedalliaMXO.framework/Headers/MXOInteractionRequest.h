//
//  MXOInteractionRequest.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXORequest, MXOInteractionRequestBuilder;

//=========================================
#pragma mark - Typedef
//=========================================

/*!
A block type used for building an ``MXOInteractionRequest`` object.
*/
typedef void (^MXOInteractionRequestBuilderBlock)(MXOInteractionRequestBuilder *builder);

//=========================================
#pragma mark - MXOInteractionRequest
//=========================================

/*!
The Interaction request object for sending Interaction data from the MXO SDK.
 
## Properties
- `properties`:  Properties map to be sent with the Interaction.
*/
@interface MXOInteractionRequest : MXORequest

//=========================================
#pragma mark - Properties
//=========================================

/*!
Properties map to be sent with the Interaction.
*/
@property (nonatomic, strong, readonly, nullable) NSDictionary<NSString *, NSString *> *properties;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOInteractionRequest``.
 
## Returns
An instance of ``MXOInteractionRequestBuilder``.
*/
- (MXOInteractionRequestBuilder *)builder;

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOInteractionRequest`` using the provided `builder` block.
 
## Parameters
- `block`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(MXOInteractionRequestBuilderBlock)block NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOInteractionRequestBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOInteractionRequest`` objects.
 
## Properties
- `interaction`: The Interaction to be sent to MXO.
- `properties`: Properties map to be sent with the Interaction.
- `onError`: Provide an MXO Error handler.
- `onSuccess`: Provide an MXO Interaction response.
*/
@interface MXOInteractionRequestBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The Interaction to be sent to MXO.
*/
@property (nonatomic, strong, nullable) MXOInteraction *interaction;

/*!
Properties map to be sent with the Interaction.
*/
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *properties;

/*!
Provide an MXO Error handler.
*/
@property (nonatomic, copy, nullable) MXORequestOnErrorBlock onError;

/*!
Provide an MXO Interaction response.
*/
@property (nonatomic, copy, nullable) MXORequestOnSuccessBlock onSuccess;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates an ``MXOInteractionRequest`` object.
 
## Returns
An instance of ``MXOInteractionRequest``.
*/
- (MXOInteractionRequest *)build;

@end

NS_ASSUME_NONNULL_END
