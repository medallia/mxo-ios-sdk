//
//  MXORequest.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOInteractionResponse, MXOInteraction;

//=========================================
#pragma mark - Typedef
//=========================================

/*!
The MXO request sent on error.
*/
typedef void (^MXORequestOnErrorBlock)(NSError *error);

/*!
The MXO request sent on success.
*/
typedef void (^MXORequestOnSuccessBlock)(MXOInteractionResponse *response);

//=========================================
#pragma mark - MXORequest
//=========================================

/*!
The request sent to MXO.
 
## Properties
- `interaction`: The Interaction to be sent to MXO.
- `onError`: The MXO error handler.
- `onSuccess`: The MXO Interaction response.
*/
@interface MXORequest : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The Interaction to be sent to MXO.
*/
@property (nonatomic, strong, readonly, nullable) MXOInteraction *interaction;

/*!
The MXO error handler.
*/
@property (nonatomic, copy, readonly, nullable) MXORequestOnErrorBlock onError;

/*!
The MXO Interaction response.
*/
@property (nonatomic, copy, readonly, nullable) MXORequestOnSuccessBlock onSuccess;

@end

NS_ASSUME_NONNULL_END
