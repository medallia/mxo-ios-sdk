//
//  MXOCaptureActivityPoint.h
//  MedalliaMXO
//
//  Copyright © 2023 Medallia. Use subject to licensing terms.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//=========================================
#pragma mark - MXOCaptureActivityPoint
//=========================================

/*!
Captures Activity when a user visits an MXO Interaction.
 
## Properties
- `identifier`: The internal MXO id of a Point.
- `path`: The location of an Activity to capture, such as a button click.
*/
@interface MXOCaptureActivityPoint : NSObject

//=========================================
#pragma mark - Properties
//=========================================

/*!
The internal MXO id of a Point.
*/
@property (nonatomic, copy, nullable, readonly) NSString *identifier;

/*!
The location of an Activity to capture, such as a button click.
*/
@property (nonatomic, copy, nullable, readonly) NSString *path;

@end

NS_ASSUME_NONNULL_END
