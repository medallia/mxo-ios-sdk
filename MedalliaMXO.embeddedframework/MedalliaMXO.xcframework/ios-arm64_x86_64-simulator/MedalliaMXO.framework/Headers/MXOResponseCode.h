//
//  MXOResponseCode.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MXOResponseCode : NSObject

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////////

@property (nonatomic, copy, nullable) NSString *value;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Instance Methods
///////////////////////////////////////////////////////////////////////////////////////////

- (instancetype)init NS_UNAVAILABLE;

///////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Class Methods
///////////////////////////////////////////////////////////////////////////////////////////

+ (nullable instancetype)initWithResponseCode:(NSString *)code
                                        error:(NSError *__autoreleasing _Nullable * _Nullable)error NS_SWIFT_NAME(init(withResponseCode:));

@end

NS_ASSUME_NONNULL_END
