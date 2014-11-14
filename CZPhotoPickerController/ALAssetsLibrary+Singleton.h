//
//  ALAssetsLibrary+Singleton.h
//  Pods
//
//  Created by Samuel Moriyasu on 14/11/14.
//
//

#import <AssetsLibrary/AssetsLibrary.h>

@interface ALAssetsLibrary (Singleton)

+ (ALAssetsLibrary*)sharedInstance;

@end
