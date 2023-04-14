//
//  MXOCaptureAttributePoint.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MXOCaptureAttributePoint : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *identifier;

@property (nonatomic, copy, nullable, readonly) NSString *path;

@end

NS_ASSUME_NONNULL_END
