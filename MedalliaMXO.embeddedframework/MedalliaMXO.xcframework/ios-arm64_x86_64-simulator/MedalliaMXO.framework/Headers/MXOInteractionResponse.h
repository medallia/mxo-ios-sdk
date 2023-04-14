//
//  MXOInteractionResponse.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MXOCaptureActivityPoint, MXOCaptureAttributePoint, MXOOptimizationPoint, MXOInteraction;

@interface MXOInteractionResponse : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

@property (nonatomic, copy, nullable, readonly) NSString *tid;

@property (nonatomic, strong, nullable, readonly) MXOInteraction *interaction;

@property (nonatomic, strong, nullable, readonly) NSArray<MXOOptimizationPoint *> *optimizationPoints;

@property (nonatomic, strong, nullable, readonly) NSArray<MXOCaptureAttributePoint *> *captureAttributePoints;

@property (nonatomic, strong, nullable, readonly) NSArray<MXOCaptureActivityPoint *> *captureActivityPoints;

@end

NS_ASSUME_NONNULL_END
