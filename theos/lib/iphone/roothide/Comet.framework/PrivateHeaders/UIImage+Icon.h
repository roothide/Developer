//
//  UIImage+Icon.h
//  Comet
//
//  Created by Noah Little on 23/4/2023.
//

#ifndef UIImage_Icon_h
#define UIImage_Icon_h

#import <UIKit/UIKit.h>

@interface UIImage (Private)
+ (instancetype)_applicationIconImageForBundleIdentifier:(NSString*)bundleIdentifier format:(int)format scale:(CGFloat)scale;
@end

#endif /* UIImage_Icon_h */
