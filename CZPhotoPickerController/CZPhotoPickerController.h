// Copyright 2013 Care Zone Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CTAssetsPickerController.h"

typedef void (^CZPhotoPickerCompletionBlock)(UIImagePickerController *imagePickerController, NSDictionary *imageInfoDict);
typedef void (^CZPhotoPickerMultipleCompletionBlock)(CTAssetsPickerController *imagePickerController, NSArray *assets);
typedef void (^CZPhotoPickerAssetCompletionBlock)(UIImagePickerController *imagePickerController, ALAsset* asset);

@interface CZPhotoPickerController : NSObject

+ (BOOL)isOS7OrHigher;
+ (BOOL)isOS8OrHigher;

/**
 Defaults to NO. Is passed to the UIImagePickerController
 */
@property(nonatomic,assign) BOOL allowsEditing;

/**
 Defaults to CGSizeZero. When set to a non-zero value, a crop
 overlay view will be displayed atop the selected image at the
 provided size.
 */
@property(nonatomic,assign) CGSize cropOverlaySize;

/**
 Allow overriding of the UIPopoverController class used to host the
 UIImagePickerController. Defaults to UIPopoverController.
 */
@property(nonatomic,copy) Class popoverControllerClass;

/**
 Defaults to YES.
*/
@property(nonatomic,assign) BOOL offerLastTaken;

/**
 Defaults to YES.
*/
@property(nonatomic,assign) BOOL saveToCameraRoll;


/**
 Defaults to NO.
 */
@property(nonatomic,assign) BOOL multipleSelection;
/**
 Defaults to NO.
 */
@property(nonatomic,assign) BOOL returnAsset;
@property(nonatomic,copy) CZPhotoPickerMultipleCompletionBlock multipleSelectionCompletionBlock;
@property(nonatomic,copy) CZPhotoPickerAssetCompletionBlock assetCompletionBlock;

@property(nonatomic,assign) UIImagePickerControllerCameraDevice cameraDevice;

/**
 @param completionBlock Called when a photo has been picked or cancelled (`imageInfoDict` will be nil if canceled). The `UIImagePickerController` has not been dismissed at the time of this being called.
 */
- (id)initWithPresentingViewController:(UIViewController *)aViewController withCompletionBlock:(CZPhotoPickerCompletionBlock)completionBlock;

- (void)dismissAnimated:(BOOL)animated;

- (void)showFromTabBar:(UITabBar *)tabBar;
- (void)showFromBarButtonItem:(UIBarButtonItem *)barButtonItem;
- (void)showFromRect:(CGRect)rect;

@end
