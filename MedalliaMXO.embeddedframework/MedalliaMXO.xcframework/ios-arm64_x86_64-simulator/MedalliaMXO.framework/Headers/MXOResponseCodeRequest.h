//
//  MXOResponseCodeRequest.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXORequest, MXOResponseCodeRequestBuilder, MXOResponseCode;

//=========================================
#pragma mark - Typedef
//=========================================

/*!
A block type used for building an ``MXOResponseCodeRequest`` object.
*/
typedef void (^MXOResponseCodeRequestBuilderBlock)(MXOResponseCodeRequestBuilder *builder);

//=========================================
#pragma mark - MXOResponseCodeRequest
//=========================================

/*!
The response code request object for sending the response code to the MXO SDK.
 
## Properties
- `responseCode`:  Response code object containing the response code value.
*/
@interface MXOResponseCodeRequest : MXORequest

//=========================================
#pragma mark - Properties
//=========================================

/*!
Response code object containing the response code value.
*/
@property (nonatomic, strong, readonly, nullable) MXOResponseCode *responseCode;

//=========================================
#pragma mark - Instance Methods
//=========================================

/*!
Creates a builder for an ``MXOResponseCodeRequest``.
 
## Returns
An instance of ``MXOResponseCodeRequestBuilder``.
*/
- (MXOResponseCodeRequestBuilder *)builder;

- (instancetype)init NS_UNAVAILABLE;

//=========================================
#pragma mark - Class Methods
//=========================================

/*!
Creates an instance of ``MXOResponseCodeRequest`` using the provided `builder` block.
 
## Parameters
- `block`: The block used to configure the instance.
*/
+ (instancetype)initWithBuilder:(MXOResponseCodeRequestBuilderBlock)block NS_SWIFT_NAME(init(withBuilder:));

@end

//=========================================
#pragma mark - MXOResponseCodeRequestBuilder
//=========================================

/*!
The builder class designed to facilitate the creation of ``MXOResponseCodeRequest`` objects.
 
## Properties
- `responseCode`: Response code object containing the response code value.
- `interaction`: The Interaction to be sent to MXO.
- `onError`: Provide an MXO Error handler.
- `onSuccess`: Provide an MXO Interaction response.
*/
@interface MXOResponseCodeRequestBuilder : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
Response code object containing the response code value.
*/
@property (nonatomic, strong, nullable) MXOResponseCode *responseCode;

/*!
The Interaction to be sent to MXO.
*/
@property (nonatomic, strong, nullable) MXOInteraction *interaction;

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
Creates an ``MXOResponseCodeRequest`` object.
 
## Returns
An instance of ``MXOResponseCodeRequest``.
*/
- (MXOResponseCodeRequest *)build;

@end

NS_ASSUME_NONNULL_END
