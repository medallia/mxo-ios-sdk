//
//  MXOInteractionResponse.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOCaptureActivityPoint, MXOCaptureAttributePoint, MXOOptimizationPoint, MXOInteraction;

//=========================================
#pragma mark - MXOInteractionResponse
//=========================================

/*!
The MXO Interaction response data.
 
## Properties
- `tid`: The unique id for this user's interaction.
- `interaction`:  The Interaction this response is for.
- `optimizationPoints`:  The MXO Interaction response for Optimization Points.
- `captureAttributePoints`:  The MXO Interaction response for Attribute Points.
- `captureActivityPoints`: The MXO Interaction response for Activity Points.
*/
@interface MXOInteractionResponse : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The unique id for this user's interaction.
*/
@property (nonatomic, copy, nullable, readonly) NSString *tid;

/*!
The Interaction this response is for.
*/
@property (nonatomic, strong, nullable, readonly) MXOInteraction *interaction;

/*!
The MXO Interaction response for Optimization Points.
*/
@property (nonatomic, strong, nullable, readonly) NSArray<MXOOptimizationPoint *> *optimizationPoints;

/*!
The MXO Interaction response for Attribute Points.
*/
@property (nonatomic, strong, nullable, readonly) NSArray<MXOCaptureAttributePoint *> *captureAttributePoints;

/*!
The MXO Interaction response for Activity Points.
*/
@property (nonatomic, strong, nullable, readonly) NSArray<MXOCaptureActivityPoint *> *captureActivityPoints;

@end

NS_ASSUME_NONNULL_END
