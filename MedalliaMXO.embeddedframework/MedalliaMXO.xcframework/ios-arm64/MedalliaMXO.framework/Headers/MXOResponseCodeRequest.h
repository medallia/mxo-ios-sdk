//
//  MXOResponseCodeRequest.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXORequest, MXOResponseCodeRequestBuilder, MXOResponseCode;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Typedef
///////////////////////////////////////////////////////////////////////////////////////////

typedef void (^MXOResponseCodeRequestBuilderBlock)(MXOResponseCodeRequestBuilder *builder);

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOResponseCodeRequest
///////////////////////////////////////////////////////////////////////////////////////////

@interface MXOResponseCodeRequest : MXORequest

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

@property (nonatomic, strong, readonly, nullable) MXOResponseCode *responseCode;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

- (MXOResponseCodeRequestBuilder *)builder;

- (instancetype)init NS_UNAVAILABLE;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Class Methods
///////////////////////////////////////////////////////////////////////////////////////////

+ (instancetype)initWithBuilder:(MXOResponseCodeRequestBuilderBlock)block NS_SWIFT_NAME(init(withBuilder:));

@end

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - MXOResponseCodeRequestBuilder
///////////////////////////////////////////////////////////////////////////////////////////

@interface MXOResponseCodeRequestBuilder : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

@property (nonatomic, strong, nullable) MXOResponseCode *responseCode;

@property (nonatomic, strong, nullable) MXOInteraction *interaction;

@property (nonatomic, copy, nullable) MXORequestOnErrorBlock onError;

@property (nonatomic, copy, nullable) MXORequestOnSuccessBlock onSuccess;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

- (MXOResponseCodeRequest *)build;

@end

NS_ASSUME_NONNULL_END